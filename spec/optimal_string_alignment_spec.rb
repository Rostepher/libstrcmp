require 'spec_helper'

RSpec.describe "Strcmp.optimal_string_alignment" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.optimal_string_alignment(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.optimal_string_alignment("", nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an Integer >= 0" do
            result = Strcmp.optimal_string_alignment("", "")
            expect(result).to be_a_kind_of(Integer)
            expect(result).to be >= 0
        end

        it "returns 0 for exact matches" do
            str = "sloth"
            expect(Strcmp.optimal_string_alignment(str, str)).to eq(0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.optimal_string_alignment("ca", "abc")).to eq(3)
        end
    end
end
