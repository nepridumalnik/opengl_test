from conans import ConanFile
from conans import CMake


class RestAsio(ConanFile):
    name = 'OpenGL Test'
    version = '1.0.0'

    settings = [
        'os',
        'build_type',
        'arch',
    ]

    options = {
        'shared': [True, False],
    }

    default_options = {
        'shared': True,
    }

    def configure(self) -> None:
        self.generators = [
            'cmake',
        ]

    def requirements(self) -> None:
        self.requires('glew/2.2.0')
        self.requires('glfw/3.3.8')

    def build(self):
        cmake = CMake(self)
        cmake.definitions['BUILD_SHARED_LIBS'] = 'ON' if self.options.shared else 'OFF'

        cmake.configure()
        cmake.build()
