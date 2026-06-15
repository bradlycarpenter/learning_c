set shell := ["powershell.exe", "-c"]

build_dir := ".\\build"
source_file := ".\\main.cpp"
exe_file_name := "Handmade.exe"
windows_subsystem_flags := "-Wl,--subsystem,windows"

build:
    zig cc -g {{ source_file }} -o {{ build_dir }}\\{{ exe_file_name }} "{{windows_subsystem_flags}}" -lgdi32

run: build
  {{build_dir}}\\{{ exe_file_name }}

debug: build
  raddbg.exe {{build_dir}}\\{{ exe_file_name }}
