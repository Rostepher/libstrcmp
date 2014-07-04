$LOAD_PATH.unshift File.join(File.dirname(__FILE__), "..")

require 'rspec'
require 'spec/strcmp_bindings'

RSpec.configure do |c|
    # configurations here
end

RSpec::Matchers.define :be_approx do |expected|
    match do |actual|
        if expected.kind_of? Float and actual.kind_of? Float
            precision = 3   # 3 decimal places
            actual.round(precision) == expected.round(precision)
        else
            actual == expected
        end
    end

    description do
        "be approximately equal to #{expected}"
    end

    failure_message do |actual|
        "expected that #{actual} was approximately equal to #{expected}"
    end

    failure_message_when_negated do |actual|
        "expected that #{actual} was not approximately equal to #{expected}"
    end
end
