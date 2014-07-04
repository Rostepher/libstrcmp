require 'spec_helper'

RSpec.describe "Strcmp.levenshtein" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.levenshtein(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.levenshtein("", nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an Integer when passed valid arguments" do
            result = Strcmp.levenshtein("", "")
            expect(result).to be_a_kind_of(Integer)
            expect(result).to be >= 0
        end

        it "returns 0 for exact matches" do
            expect(Strcmp.levenshtein("gon", "gon")).to eq(0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.levenshtein("mitten", "")).to eq(6)
            expect(Strcmp.levenshtein("", "kitten")).to eq(6)
            expect(Strcmp.levenshtein("kitten", "sitting")).to eq(3)
        end
    end
end
