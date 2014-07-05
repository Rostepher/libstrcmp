require 'rake'
require 'rake/clean'
require 'rspec/core/rake_task'


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

task :default => ["build:lib", "build:include"]

task :bundle => ["Gemfile"] do
    sh "bundle install"
end

namespace :build do
    task :objects => OBJECT_DIR
    SOURCE_FILES.each do |source|
        # replace source dir with object dir
        object = source.gsub(/^#{SOURCE_DIR}/, "#{OBJECT_DIR}")
        object = object.sub(/\.c$/, '.o')

        # create file task for each source
        file object => [source] do
            # create directory
            mkdir_p object.pathmap("%d").strip

            # compile source
            sh "#{CC} #{CFLAGS} -I./#{SOURCE_DIR} -c -o #{object} #{source}"
        end

        # add file task to :objects
        task :objects => object
    end
    CLEAN.include('**/*.o', 'build')

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
end

# spec task
RSpec::Core::RakeTask.new(:spec) do |t|
    t.verbose = false
end

task :install do

end

task :uninstall do

end
