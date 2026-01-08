# Examples CMakeLists.txt

# Dashboard example
add_executable(dashboard dashboard/dashboard.cpp)
target_link_libraries(dashboard PRIVATE ZeroJS::ZeroJS)

# Chart demo example
add_executable(chart_demo chart_demo/chart_demo.cpp)
target_link_libraries(chart_demo PRIVATE ZeroJS::ZeroJS)

# Habit tracker example
add_executable(habit_tracker habit_tracker/habit_tracker.cpp)
target_link_libraries(habit_tracker PRIVATE ZeroJS::ZeroJS)

# Personal portfolio example
add_executable(personal_portfolio personal_portfolio/personal_portfolio.cpp)
target_link_libraries(personal_portfolio PRIVATE ZeroJS::ZeroJS)

# System monitor example
add_executable(system_monitor system_monitor/system_monitor.cpp)
target_link_libraries(system_monitor PRIVATE ZeroJS::ZeroJS)

# Documentation website example
add_executable(doc_website doc_website/doc_website.cpp)
target_link_libraries(doc_website PRIVATE ZeroJS::ZeroJS)

# Set output directories to match the source structure
set_target_properties(dashboard PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dashboard
)
set_target_properties(chart_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/chart_demo
)
set_target_properties(habit_tracker PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/habit_tracker
)
set_target_properties(personal_portfolio PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/personal_portfolio
)
set_target_properties(system_monitor PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/system_monitor
)
set_target_properties(doc_website PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc_website
)
