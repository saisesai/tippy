import os
import sys
import shutil

install_dir = "../dist"

install_list = [
    "../runtime/bin/x64/glfw3.dll",
    "../runtime/bin/x64/libEGL.dll",
    "../runtime/bin/x64/libGLESv2.dll",
    "../cmake-build-debug/tippy-platform-windows.exe"
]


def clean_install_dir():
    if os.path.exists(install_dir):
        shutil.rmtree(install_dir)
    os.makedirs(install_dir)


if __name__ == '__main__':
    clean_install_dir()

    for file in install_list:
        try:
            shutil.copy(file, install_dir)
        except FileNotFoundError:
            print("file {} not found, please recompile project!".format(file))
            sys.exit(-1)

    print("install successful!")
