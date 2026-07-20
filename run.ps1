If (Test-Path -Path build/Pong.exe)
{
    Remove-Item build/Pong.exe
}

cmake -B build
cmake --build build
./build/Pong.exe