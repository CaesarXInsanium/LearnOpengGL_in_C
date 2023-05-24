project(
  'LearnOpenGL',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debug',
    'debug=true',
    #'optimization=3',
    'c_std=c18'
  ]
)

SRC = [
  'src/main.c',
  'src/window.c',
  'src/shader.c',
  'src/mesh.c',
  'src/texture.c',
]

INC = [
  include_directories('include'),
]

DEPS = [
    dependency('glew'),
    dependency('glfw3'),
    dependency('cglm'),
    dependency('libpng'),
]
executable(
          'learn-gl',
          SRC, 
          install : true,
          include_directories: INC,
          dependencies: DEPS,
)
