Gem::Specification.new do |s|
  s.name        = 'count_bits'
  s.version     = '0.1.4'
  s.summary     = 'counts bits'
  s.description = 'still counts bits'
  s.authors     = ["Wolfgang Teuber"]
  s.email       = 'knugie@gmx.net'
  s.files       = Dir['lib/**/*.rb'] + Dir['ext/**/*.{c,h,rb}']
  s.extensions  = Dir['ext/**/extconf.rb']
  s.executables = ['count_bits']
  s.homepage    = 'https://github.com/knugie'
end

