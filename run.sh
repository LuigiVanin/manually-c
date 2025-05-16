if [ ! -d "./build" ]; then
    mkdir build
fi

if [ ! -d "./build/_deps" ]; then
    mkdir build/_deps
fi

flags="-g -Wall -Wextra"

build_lib() {
    echo "Building library..."
    # clang -fPIC -shared -o ./build/_deps/liblib.so ./lib/lib.c
    ./lib/build.sh

    # check if ./lib/liblib.so exists
    if [ ! -f "./lib/liblib.so" ]; then
        echo "Library build failed!"
        exit 1
    fi

    mv ./lib/liblib.so ./build/_deps/liblib.so

    echo -e "Library build completed!\n"
}

build() {
    
    echo "Building..."
    clang $flags -o ./build/playground main.c util.c \
        -I./extern/raylib/build/raylib/include \
        -L./extern/raylib/build/raylib \
        -lraylib -lm -lpthread -ldl -lX11 \
        -L./build/_deps \
        -llib 
    echo -e "Build Completed! \n"
}

run() {
    echo "Running..."
    echo -e "------------------------\n"
    
    LD_LIBRARY_PATH=./build/_deps ./build/playground
}

if [ "$1" == "--build" ]; then
    build_lib
    build
elif [ "$1" == "--run" ]; then
    run
elif [ "$1" == "--start" ] || [ -z "$1" ]; then
    build_lib
    build
    run
else
    echo "Invalid argument. Use --build, --run, or --start."
fi


