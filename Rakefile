require 'rake'
require 'rake/clean'
require 'rspec/core/rake_task'

CC          = "clang"
CFLAGS      = "-std=c99 -ggdb -Wall -fpic"
LDFLAGS     = "-lm"

TARGET      = "libstrcmp.so"
SOURCE_DIR  = "src"
OBJECT_DIR  = "build"
LIBRARY_DIR = "lib"
INCLUDE_DIR = "include"

SOURCE_FILES = FileList.new("#{SOURCE_DIR}/**/*.c") do |fl|
    fl.exclude(/metaphone/)
end

desc "Default task builds project"
task :default => :build

desc "Use bundler to install necessary gems"
task :bundle => "Gemfile" do
    sh "bundle install"
end
CLOBBER.include("Gemfile.lock")

desc "Compile and link source files into a shared object file"
task :build => :link do
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

desc "Compile source files to object files"
task :compile
SOURCE_FILES.each do |source|
    # replace source dir with object dir
    object = source.gsub(/^#{SOURCE_DIR}/, "#{OBJECT_DIR}")
    object = object.sub(/\.c$/, '.o')

    # create file task for each source
    file object => source do
        # create directory
        mkdir_p object.pathmap("%d").strip

        # compile source
        sh "#{CC} #{CFLAGS} -I./#{SOURCE_DIR} -c -o #{object} #{source}"
    end

    # add file task to :objects
    task :compile => object
end
CLEAN.include('**/*.o', 'build')

desc "Link compiled object files to a shared object file (library)"
task :link => :compile do
    # find all object files in build
    objects = FileList["#{OBJECT_DIR}/**/*.o"].join(' ')

    # create lib
    mkdir_p LIBRARY_DIR

    # link
    output = File.join(LIBRARY_DIR, TARGET)
    sh "#{CC} #{LDFLAGS} #{objects} -shared -o #{output}"
end
CLOBBER.include(LIBRARY_DIR)

desc "Runs the RSpec test suite"
RSpec::Core::RakeTask.new(:spec) do |t|
    t.verbose = false
end

desc "Installs library and related documentation"
task :install

desc "Uninstalls library and related documentation"
task :uninstall
