require 'ffi'

module Strcmp
    extend FFI::Library

    ffi_lib "src/strcmp.h"

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
    end

    def jaro_winkler(str1, str2)
        is_string(str1)
        is_string(str2)
    end

    def levenshtein(str1, str2)
        is_string(str1)
        is_string(str2)
    end

    def optimal_string_alignment(str1, str2)
        is_string(str1)
        is_string(str2)
    end

    def sift3(str1, str2)
        is_string(str1)
        is_string(str2)
    end

    def sift3B(str1, str2)
        is_string(str1)
        is_string(str2)
    end

    def soundex(str)
        is_string(str)
    end

    def refined_soundex(str)
        is_string(str)
        result = ffi_refined_soundex(str).read_pointer
        String.new(result.read_string.force_encoding('UTF-8'))
        result.free_pointer
    end

    private

    # distance
    attatch_function :ffi_damerau_levenshtein, :damerau_levenshtein, [:string, :string], :uint
    attatch_function :ffi_hamming, :hamming, [:string, :string], :uint
    attatch_function :ffi_jaro, :jaro, [:string, :string], :double
    attatch_function :ffi_jaro_winkler, :jaro_winkler, [:string, :string], :double
    attatch_function :ffi_levenshtein, :levenshtein, [:string, :string], :uint
    attatch_function :ffi_optimal_string_alignment, :optimal_string_alignment, [:string, :string], :unit
    attatch_function :ffi_sift3, :sift3, [:string, :string, :uint], :double
    attatch_function :ffi_sift3B, :sift3B, [:string, :string, :unit, :double], :double

    # phonetic
    attatch_function :ffi_soundex, :soundex, [:string], :string
    attatch_function :ffi_refined_soundex, :refined_soundex, [:string], :string

    # helper to verify strings
    def is_string(object)
        unless object.kind_of? String
            raise TypeError,
                "Wrong argument type #{object.class} (expected String)"
        end
    end
end
