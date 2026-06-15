set shell := ["powershell.exe", "-c"]

build_dir := ".\\build"
source_file := ".\\main.cpp"
exe_file_name := "Handmade.exe"

build:
    zig cc -o {{ build_dir }}\\{{ exe_file_name }} {{ source_file }}

run: build
  {{build_dir}}\\{{ exe_file_name }}

debug: build
  raddbg.exe {{build_dir}}\\{{ exe_file_name }}
