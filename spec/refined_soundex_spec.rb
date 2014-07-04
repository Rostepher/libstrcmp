require 'spec_helper'

RSpec.describe "Strcmp.refined_soundex" do
    context "when passed invalid arguments" do
        it "raises a TypeError" do
            expect { Strcmp.refined_soundex(nil) }.to raise_error(TypeError)
        end
    end

    context "when passed valid arguments" do
        it "returns an String when provided valid arguments" do
            expect(Strcmp.refined_soundex("")).to be_a_kind_of(String)
        end

        it "returns an empty string when passed an empty string" do
            expect(Strcmp.refined_soundex("")).to eq("")
        end

        it "returns correct values for passed strings" do
            expect(Strcmp.refined_soundex("Braz")).to eq("B1905")
            expect(Strcmp.refined_soundex("Broz")).to eq("B1905")
            expect(Strcmp.refined_soundex("Caren")).to eq("C30908")
            expect(Strcmp.refined_soundex("Hayers")).to eq("H093")
            expect(Strcmp.refined_soundex("Lambert")).to eq("L7081096")
            expect(Strcmp.refined_soundex("Noulton")).to eq("N807608")
        end
    end
end
