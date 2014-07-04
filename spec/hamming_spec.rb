require 'spec_helper'

RSpec.describe "Strcmp.hamming" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.levenshtein(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.levenshtein("", nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an Integer" do
            result = Strcmp.hamming("", "")
            expect(result).to be_a_kind_of(Integer)
            expect(result).to be >= 0
        end

        it "returns -1 when arguments have different lengths" do
            expect(Strcmp.hamming("", "smitten")).to eq(-1)
        end

        it "returns 0 for exact matches" do
            expect(Strcmp.hamming("sloth", "sloth")).to eq(0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.hamming("sloth", "sloht")).to eq(2)
            expect(Strcmp.hamming("kitten", "mitten")).to eq(1)
        end
    end
end
