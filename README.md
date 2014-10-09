# Crc32

[![Gem Version](https://badge.fury.io/rb/crc32.svg)](http://badge.fury.io/rb/crc32)

This gem implements Intel's slicing-by-8 CRC32 calculation algorithm for ruby. This should be approximately 4 times as fast as Zlib's CRC32 implementation.

## Installation

Add this line to your application's Gemfile:

    gem 'crc32'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install crc32

## Usage

To calculate CRC32 for some data:

    Crc32.calculate(data, data_length, previous_crc32)

For example:

```ruby
require 'crc32'
Crc32.calculate('12397538', 8, 0)
```

## Credits

* [Stephan Brumme](http://stephan-brumme.com/aboutme/vitae.html) for his [wonderful explanation of CRC32 algorithms](http://create.stephan-brumme.com/crc32/).
* [Intel Corp.](http://intel.com) for [slicing-by-8](http://sourceforge.net/projects/slicing-by-8/) algorithm.

## History

* 1.0.1 - Initial release.

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
