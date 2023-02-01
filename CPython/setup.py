from distutils.core import setup, Extension

module = Extension('spam', 
                   define_macros = [('MAJOR_VERSION', '1'), ('MINOR_VERSION', '0')],
                   sources = ['spammodule.c'])

setup(name = 'spam',
      version = '1.0',
      description = 'spam module',
      
      ext_modules = [module])