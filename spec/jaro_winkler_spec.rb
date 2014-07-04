require 'spec_helper'

RSpec.describe "Strcmp.jaro" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.jaro(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.jaro("", nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns a Float" do
            expect(Strcmp.jaro("", "")).to be_a_kind_of(Float)
        end

        it "returns 1.0 for exact matches" do
            str = "sloth"
            expect(Strcmp.jaro(str, str)).to eq(1.0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.jaro("martha", "marhta")).to be_approx(0.944)
            expect(Strcmp.jaro("dwayne", "duane")).to be_approx(0.822)
            expect(Strcmp.jaro("dixon", "dicksonx")).to be_approx(0.767)
        end
    end
end

RSpec.describe "Strcmp.jaro_winkler" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.jaro_winkler(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.jaro_winkler("", nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns a Float" do
            expect(Strcmp.jaro_winkler("", "")).to be_a_kind_of(Float)
        end

        it "returns 1.0 for exact matches" do
            str = "sloth"
            expect(Strcmp.jaro_winkler(str, str)).to eq(1.0)
        end

        it "returns correct values for non-matching strings" do
            expect(Strcmp.jaro_winkler("martha", "marhta")).to be_approx(0.961)
            expect(Strcmp.jaro_winkler("dwayne", "duane")).to be_approx(0.840)
            expect(Strcmp.jaro_winkler("dixon", "dicksonx")).to be_approx(0.813)
        end
    end
end
