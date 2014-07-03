require 'rake'
require 'rake/clean'

CC          = "clang"
PKGS        = ""
CFLAGS      = "-std=c99 -ggdb -Wall -fpic"
LDFLAGS     = (`pkg-config --libs #{PKGS}`.strip << " -lm").strip

TARGET      = "libstrcmp.so"
SOURCE_DIR  = "src"
OBJECT_DIR  = "build"
LIBRARY_DIR = "lib"
INCLUDE_DIR = "include"

SOURCE_FILES = FileList.new("#{SOURCE_DIR}/**/*.c") do |fl|
    fl.exclude(/metaphone/)
end

directory OBJECT_DIR

task :default => :all

task :all => ["build:lib", "build:include"]

namespace :build do
    task :deps do

    end

    task :objects do
        SOURCE_FILES.each do |source|
            # replace source dir with object dir
            object = source.gsub(/^#{SOURCE_DIR}/, "#{OBJECT_DIR}")
            object = object.sub(/\.c$/, '.o')

            # create directory
            mkdir_p object.pathmap("%d").strip

            # compile source
            sh "#{CC} #{CFLAGS} -I./#{SOURCE_DIR} -c -o #{object} #{source}"
        end
    end
    CLEAN.include('**/*.o', 'build')

    task :include do
        # grab all relavent headers
        headers = FileList.new("#{SOURCE_DIR}/**/*.h") do |fl|
            fl.exclude(/macros\.h/)
        end

        # create include dir
        mkdir_p INCLUDE_DIR

        # copy headers into include dir
        cp(headers.join(' '), INCLUDE_DIR)
    end
    CLOBBER.include(INCLUDE_DIR)

    task :lib => :objects do
        # find all object files in build
        object_files = FileList["#{OBJECT_DIR}/**/*.o"].join(' ')

        # create lib
        mkdir_p LIBRARY_DIR

        # link
        output = File.join(LIBRARY_DIR, TARGET)
        sh "#{CC} #{LDFLAGS} #{object_files} -shared -o #{output}"
    end
    CLOBBER.include(LIBRARY_DIR)
end

namespace :test do

end

task :install do

end

task :uninstall do

end

