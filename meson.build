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
]

INC = [
include_directories('include'),
include_directories('BMPGL')
]

DEPS = [
    dependency('glew'),
    dependency('glfw3'),
    dependency('cglm'),

]
BMPGL = library(
  'bpm',
  ['BMPGL/src/bmp.c'],
  include_directories: INC,
)
executable(
          'learn-gl',
          SRC, 
          install : true,
          include_directories: INC,
          dependencies: DEPS,
          link_with: BMPGL
)
