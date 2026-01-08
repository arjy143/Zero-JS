#!/usr/bin/env bash
set -e

CXX=${CXX:-g++}
CXXFLAGS="-std=c++17 -O2 -Wall -Wextra"

FILES=(
  "examples/dashboard/dashboard.cpp"
  "examples/chart_demo/chart_demo.cpp"
  "examples/habit_tracker/habit_tracker.cpp"
  "examples/personal_portfolio/personal_portfolio.cpp"
  "examples/system_monitor/system_monitor.cpp"
)

for file in "${FILES[@]}"; do
  dir="$(dirname "$file")"
  name="$(basename "$file" .cpp)"
  out="$dir/$name"

  echo "==> Building $out"
  $CXX $CXXFLAGS "$file" -o "$out"
done

echo
echo "Build complete."
echo "Run with:"
for file in "${FILES[@]}"; do
  dir="$(dirname "$file")"
  name="$(basename "$file" .cpp)"
  echo "  ./$dir/$name"
done
