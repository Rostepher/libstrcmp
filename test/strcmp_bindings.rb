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
            ffi_damerau_levenshtein(str1, str2)
        end

        def hamming(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_hamming(str1, str2)
        end

        def jaro(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_jaro(str1, str2)
        end

        def jaro_winkler(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_jaro_winkler(str1, str2)
        end

        def levenshtein(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_levenshtein(str1, str2)
        end

        def optimal_string_alignment(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_optimal_string_alignment(str1, str2)
        end

        def sift3(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_sift3(str1, str2)
        end

        def sift3B(str1, str2)
            is_string(str1)
            is_string(str2)
            ffi_sift3B(str1, str2)
        end

        def soundex(str)
            is_string(str)
            ptr = ffi_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        def refined_soundex(str)
            is_string(str)
            ptr = ffi_refined_soundex(str)
            result = String.new(ptr.read_string)
            LibC.free(ptr)

            result
        end

        private

        # distance
        attach_function :ffi_damerau_levenshtein, :damerau_levenshtein, [:string, :string], :uint
        attach_function :ffi_hamming, :hamming, [:string, :string], :int
        attach_function :ffi_jaro, :jaro, [:string, :string], :double
        attach_function :ffi_jaro_winkler, :jaro_winkler, [:string, :string], :double
        attach_function :ffi_levenshtein, :levenshtein, [:string, :string], :uint
        attach_function :ffi_optimal_string_alignment, :optimal_string_alignment, [:string, :string], :uint
        attach_function :ffi_sift3, :sift3, [:string, :string, :uint], :double
        attach_function :ffi_sift3B, :sift3B, [:string, :string, :uint, :double], :double

        # phonetic
        attach_function :ffi_soundex, :soundex, [:string], :pointer
        attach_function :ffi_refined_soundex, :refined_soundex, [:string], :pointer

        # helper to verify strings
        def is_string(object)
            unless object.kind_of? String
                raise TypeError,
                    "Wrong argument type #{object.class} (expected String)"
            end
        end
    end
end
