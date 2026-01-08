// Simple HTTP server to serve static files
// Usage: ./server [port] [directory]
// Default: port 8080, current directory

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

std::string get_content_type(const std::string& path) {
    if (path.ends_with(".html")) return "text/html";
    if (path.ends_with(".css")) return "text/css";
    if (path.ends_with(".js")) return "application/javascript";
    if (path.ends_with(".png")) return "image/png";
    if (path.ends_with(".jpg") || path.ends_with(".jpeg")) return "image/jpeg";
    if (path.ends_with(".svg")) return "image/svg+xml";
    if (path.ends_with(".json")) return "application/json";
    return "text/plain";
}

std::string read_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) return "";
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

void handle_request(int client_fd, const std::string& base_dir) {
    char buffer[4096] = {0};
    read(client_fd, buffer, sizeof(buffer) - 1);

    std::string request(buffer);
    std::cout << "Request:\n" << request << "\n";

    // Parse GET request
    if (request.substr(0, 3) != "GET") {
        std::cout << "get request\n";
        std::string response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        write(client_fd, response.c_str(), response.size());
        close(client_fd);
        return;
    }

    // Extract path
    size_t path_start = request.find(' ') + 1;
    size_t path_end = request.find(' ', path_start);
    std::string url_path = request.substr(path_start, path_end - path_start);
    std::cout << "log: url_path: " << url_path << "\n";

    // Default to index.html
    if (url_path == "/") url_path = "/index.html";

    // Security: prevent directory traversal
    if (url_path.find("..") != std::string::npos) {
        std::string response = "HTTP/1.1 403 Forbidden\r\n\r\n";
        write(client_fd, response.c_str(), response.size());
        close(client_fd);
        return;
    }
    if (url_path == "/api/click") 
    {
        static int counter = 0;
        counter++;
        std::cout << "Button was clicked! counter = " << counter << std::endl;
        
        std::string body = "Clicks: " + std::to_string(counter);
        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "\r\n" + body;

        write(client_fd, response.c_str(), response.size());
        close(client_fd);
        return;
    }

    std::string file_path = base_dir + url_path;
    std::string content = read_file(file_path);

    std::string response;
    if (content.empty()) {
        response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n"
                   "<h1>404 Not Found</h1><p>File not found: " + url_path + "</p>";
        std::cout << "404 " << url_path << std::endl;
    } else {
        std::string content_type = get_content_type(file_path);
        response = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: " + content_type + "\r\n"
                   "Content-Length: " + std::to_string(content.size()) + "\r\n"
                   "\r\n" + content;
        std::cout << "200 " << url_path << std::endl;
    }

    write(client_fd, response.c_str(), response.size());
    close(client_fd);
}

int main(int argc, char* argv[]) {
    int port = 8080;
    std::string base_dir = ".";

    if (argc > 1) port = std::stoi(argv[1]);
    if (argc > 2) base_dir = argv[2];

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Failed to bind to port " << port << std::endl;
        return 1;
    }

    if (listen(server_fd, 10) < 0) {
        std::cerr << "Failed to listen" << std::endl;
        return 1;
    }

    std::cout << "Serving " << base_dir << " at http://localhost:" << port << std::endl;
    std::cout << "Press Ctrl+C to stop\n" << std::endl;

    while (true) {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);

        if (client_fd >= 0) {
            handle_request(client_fd, base_dir);
        }
    }

    close(server_fd);
    return 0;
}
