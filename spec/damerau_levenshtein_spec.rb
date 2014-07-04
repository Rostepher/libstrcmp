require 'spec_helper'

RSpec.describe "Strcmp.damerau_levenshtein" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.damerau_levenshtein(nil, "", 0) }.to raise_error(TypeError)
            expect { Strcmp.damerau_levenshtein("", nil, 0) }.to raise_error(TypeError)
            expect { Strcmp.damerau_levenshtein("", "", -1) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an Integer >= 0" do
            result = Strcmp.damerau_levenshtein("", "")
            expect(result).to be_a_kind_of(Integer)
            expect(result).to be >= 0
        end

        it "returns 0 for exact matches" do
            str = "sloth"
            expect(Strcmp.damerau_levenshtein(str, str)).to eq(0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.damerau_levenshtein("ca", "abc")).to eq(2)
            expect(Strcmp.damerau_levenshtein("sloth", "")).to eq(5)
        end
    end
end
