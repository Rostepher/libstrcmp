require 'ffi'

module LibC
    extend FFI::Library

    ffi_lib FFI::Library::LIBC

    # attatch free
    attach_function :free, [:pointer], :void
end

module Strcmp
    class << self
        extend FFI::Library

        lib_dir = File.expand_path(File.join(File.dirname(__FILE__), "../lib"))
        ffi_lib File.join(lib_dir, "libstrcmp.so")

        def damerau_levenshtein(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_damerau_levenshtein(str1, str2)
        end

        def hamming(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_hamming(str1, str2)
        end

        def jaro(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_jaro(str1, str2)
        end

        def jaro_winkler(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_jaro_winkler(str1, str2)
        end

        def levenshtein(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_levenshtein(str1, str2)
        end

        def optimal_string_alignment(str1, str2)
            is_string(str1)
            is_string(str2)

            unsafe_optimal_string_alignment(str1, str2)
        end

        def sift3(str1, str2, max_offset)
            is_string(str1)
            is_string(str2)
            is_uint(max_offset)

            unsafe_sift3(str1, str2, max_offset)
        end

        def sift3B(str1, str2, max_offset, max_dist)
            is_string(str1)
            is_string(str2)
            is_uint(max_offset)
            is_double(max_dist)

            unsafe_sift3B(str1, str2, max_offset, max_dist)
        end

        def soundex(str)
            is_string(str)
            ptr = unsafe_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        def refined_soundex(str)
            is_string(str)
            ptr = unsafe_refined_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        private

        # distance
        attach_function :unsafe_damerau_levenshtein, :damerau_levenshtein, [:string, :string], :uint
        attach_function :unsafe_hamming, :hamming, [:string, :string], :int
        attach_function :unsafe_jaro, :jaro, [:string, :string], :double
        attach_function :unsafe_jaro_winkler, :jaro_winkler, [:string, :string], :double
        attach_function :unsafe_levenshtein, :levenshtein, [:string, :string], :uint
        attach_function :unsafe_optimal_string_alignment, :optimal_string_alignment, [:string, :string], :uint
        attach_function :unsafe_sift3, :sift3, [:string, :string, :uint], :double
        attach_function :unsafe_sift3B, :sift3B, [:string, :string, :uint, :double], :double

        # phonetic
        attach_function :unsafe_soundex, :soundex, [:string], :pointer
        attach_function :unsafe_refined_soundex, :refined_soundex, [:string], :pointer

        # helper to verify strings
        def is_double(object)
            unless object.kind_of? Float
                raise TypeError,
                    "Wrong argument type #{object.class} (expected Float)"
            end
        end

        def is_string(object)
            unless object.kind_of? String
                raise TypeError,
                    "Wrong argument type #{object.class} (expected String)"
            end
        end

        def is_uint(object)
            unless object.kind_of? Integer and object >= 0
                raise TypeError,
                    "Wrong argument type #{object.class} (expected Integer >= 0)"
            end
        end
    end
end
