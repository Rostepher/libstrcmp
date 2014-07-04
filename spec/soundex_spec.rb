require 'spec_helper'

RSpec.describe "Strcmp.soundex" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.soundex(nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an String when provided valid arguments" do
            expect(Strcmp.soundex("")).to be_a_kind_of(String)
        end

        it "returns an empty string when passed an empty string" do
            expect(Strcmp.soundex("")).to eq("")
        end

        it "returns correct values for passed strings" do
            expect(Strcmp.soundex("Soundex")).to eq("S532")
            expect(Strcmp.soundex("Example")).to eq("E251")
            expect(Strcmp.soundex("Sownteks")).to eq("S532")
            expect(Strcmp.soundex("Ekzampul")).to eq("E251")
            expect(Strcmp.soundex("Euler")).to eq("E460")
            expect(Strcmp.soundex("Gauss")).to eq("G200")
            expect(Strcmp.soundex("Hilbert")).to eq("H416")
            expect(Strcmp.soundex("Knuth")).to eq("K530")
            expect(Strcmp.soundex("Lloyd")).to eq("L300")
            expect(Strcmp.soundex("Lukasiewicz")).to eq("L222")
            expect(Strcmp.soundex("Ellery")).to eq("E460")
            expect(Strcmp.soundex("Ghosh")).to eq("G200")
            expect(Strcmp.soundex("Heilbronn")).to eq("H416")
            expect(Strcmp.soundex("Kant")).to eq("K530")
            expect(Strcmp.soundex("Ladd")).to eq("L300")
            expect(Strcmp.soundex("Lissajous")).to eq("L222")
            expect(Strcmp.soundex("Wheaton")).to eq("W350")
            expect(Strcmp.soundex("Burroughs")).to eq("B620")
            expect(Strcmp.soundex("Burrows")).to eq("B620")
            expect(Strcmp.soundex("O'Hara")).to eq("O600")
            expect(Strcmp.soundex("Washington")).to eq("W252")
            expect(Strcmp.soundex("Lee")).to eq("L000")
            expect(Strcmp.soundex("Gutierrez")).to eq("G362")
            expect(Strcmp.soundex("Pfister")).to eq("P236")
            expect(Strcmp.soundex("Jackson")).to eq("J250")
            expect(Strcmp.soundex("Tymczak")).to eq("T522")
            expect(Strcmp.soundex("VanDeusen")).to eq("V532")
            expect(Strcmp.soundex("Ashcraft")).to eq("A261")
        end
    end
end
