with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "glew";
    nativeBuildInputs = [pkg-config];
    buildInputs = [
    gcc
    meson
    ninja
    glfw3
    cglm	
    libpng
    ];
}
