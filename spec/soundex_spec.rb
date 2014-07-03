require 'spec_helper'

RSpec.describe "Strcmp#levenshtein" do
    it "raises a TypeError if provided invalid arguments" do
        expect{ Strcmp.levenshtein(nil, nil) }.to raise_error(TypeError)
    end
end
