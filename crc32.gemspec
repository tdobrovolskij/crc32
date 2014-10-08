# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'crc32/version'

Gem::Specification.new do |spec|
  spec.name          = "crc32"
  spec.version       = Crc32::VERSION
  spec.authors       = ["Tadeus Dobrovolskij"]
  spec.email         = ["root@tad-do.net"]
  spec.description   = %q{Very fast CRC32 calculation based on Intel's slicing-by-8 algorithm.}
  spec.summary       = %q{CRC32 slicing-by-8 implementation for Ruby.}
  spec.homepage      = "https://github.com/tdobrovolskij/crc32"
  spec.license       = "GPLv2"

  spec.files         = Dir.glob("ext/**/*.{c,rb,h}") +
                        Dir.glob("lib/**/*.rb")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake", "~> 10.3"
  spec.add_development_dependency "rake-compiler", "~> 0.9"

  spec.extensions << "ext/crc32/extconf.rb"
end
