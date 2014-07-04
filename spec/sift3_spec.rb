require 'spec_helper'

RSpec.describe "Strcmp.sift3" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.sift3(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.sift3("", nil) }.to raise_error(TypeError)
            expect { Strcmp.sift3("", "", -1) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns a Float" do
            expect(Strcmp.sift3("", "")).to be_a_kind_of(Float)
        end

        it "returns 0.0 for exact matches" do
            str = "sloth"
            expect(Strcmp.sift3(str, str)).to eq(0.0)
        end

        it "returns correct values for non-matching strings" do
        end
    end
end

RSpec.describe "Strcmp.sift3B" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.sift3B(nil, "") }.to raise_error(TypeError)
            expect { Strcmp.sift3B("", nil) }.to raise_error(TypeError)
            expect { Strcmp.sift3B("", "", -1) }.to raise_error(TypeError)
            expect { Strcmp.sift3B("", "", 0, -1.0) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns a Float" do
            expect(Strcmp.sift3B("", "")).to be_a_kind_of(Float)
        end

        it "returns 0.0 for exact matches" do
            str = "sloth"
            expect(Strcmp.sift3B(str, str)).to eq(0.0)
        end

        it "returns correct values for non-matching strings" do
        end
    end
end
