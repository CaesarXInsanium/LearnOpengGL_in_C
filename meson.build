project(
  'LearnOpenGL',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debug',
    'debug=true',
    'optimization=3',
    'c_std=gnu18'
  ]
)

SRC = [
  'src/main.c',
  'src/window.c',
  'src/shader.c',
  'src/mesh.c',
  'src/texture.c',
  'src/gl.c',
]

INC = [
  include_directories('include'),
]

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

DEPS = [
    dependency('glfw3'),
    dependency('cglm'),
    dependency('libpng'),
    m_dep,
]

executable(
          'learn-gl',
          SRC, 
          install : true,
          include_directories: INC,
          dependencies: DEPS,
          c_args: ['-lm']
)
