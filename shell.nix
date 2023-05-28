with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "glew";
    nativeBuildInputs = [pkg-config];
    buildInputs = [
    gcc
    meson
    ninja
    glew
    glfw3
    cglm	
    libpng
    ];
}
