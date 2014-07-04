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

        def damerau_levenshtein(str1, str2, alpha_size=256)
            ensure_string(str1)
            ensure_string(str2)
            ensure_uint(alpha_size)

            unsafe_damerau_levenshtein(str1, str2, alpha_size)
        end

        def hamming(str1, str2)
            ensure_string(str1)
            ensure_string(str2)

            unsafe_hamming(str1, str2)
        end

        def jaro(str1, str2)
            ensure_string(str1)
            ensure_string(str2)

            unsafe_jaro(str1, str2)
        end

        def jaro_winkler(str1, str2)
            ensure_string(str1)
            ensure_string(str2)

            unsafe_jaro_winkler(str1, str2)
        end

        def levenshtein(str1, str2)
            ensure_string(str1)
            ensure_string(str2)

            unsafe_levenshtein(str1, str2)
        end

        def optimal_string_alignment(str1, str2)
            ensure_string(str1)
            ensure_string(str2)

            unsafe_optimal_string_alignment(str1, str2)
        end

        def sift3(str1, str2, max_offset=5)
            ensure_string(str1)
            ensure_string(str2)
            ensure_uint(max_offset)

            unsafe_sift3(str1, str2, max_offset)
        end

        def sift3B(str1, str2, max_offset=5, max_dist=64.0)
            ensure_string(str1)
            ensure_string(str2)
            ensure_uint(max_offset)
            ensure_double(max_dist)
            ensure_positive(max_dist)

            unsafe_sift3B(str1, str2, max_offset, max_dist)
        end

        def soundex(str)
            ensure_string(str)
            ptr = unsafe_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        def refined_soundex(str)
            ensure_string(str)
            ptr = unsafe_refined_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        private

        # distance
        attach_function :unsafe_damerau_levenshtein, :damerau_levenshtein, [:string, :string, :uint], :uint
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

        # helper to ensure strings
        def ensure_double(object)
            unless object.kind_of? Float
                raise TypeError,
                    "Wrong argument type #{object.class} (expected Float)"
            end
        end

        def ensure_string(object)
            unless object.kind_of? String
                raise TypeError,
                    "Wrong argument type #{object.class} (expected String)"
            end
        end

        def ensure_uint(object)
            unless object.kind_of?(Integer) && object >= 0
                raise TypeError,
                    "Wrong argument type #{object.class} (expected Integer >= 0)"
            end
        end

        def ensure_positive(object)
            unless object.kind_of?(Numeric) && object >= 0
                raise TypeError,
                    "Wrong argumet type #{object.class} (expected Numeric >= 0)"
            end
        end
    end
end
