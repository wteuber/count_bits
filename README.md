                                 _          _         _
                                ( )_       ( )     _ ( )_
       ___    _    _   _   ___  | ,_)      | |_   (_)| ,_)  ___
     /'___) /'_`\ ( ) ( )/' _ `\| |        | '_`\ | || |  /',__)
    ( (___ ( (_) )| (_) || ( ) || |_       | |_) )| || |_ \__, \
    `\____)`\___/'`\___/'(_) (_)`\__)      (_,__/'(_)`\__)(____/
                                     ______
                                    (______)

## Why?
  Because it's fast.
  https://gist.github.com/knugie/3865903

## How?
    $ git clone git@github.com:knugie/count_bits.git
    $ cd count_bits
    $ gem build count_bits.gemspec
    $ gem install count_bits-0.1.4.gem
    $ irb
    :001 > require 'count_bits'
    => true
    :002 > count_bits(1234567890)
    => 12
