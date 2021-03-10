require 'set'
class String
    def red; "\e[31m#{self}\e[0m" end
    def green; "\e[32m#{self}\e[0m" end
    def blue; "\e[34m#{self}\e[0m" end
end

def getRandomNumber(n)
    numbers = Set.new
    while numbers.size < n do numbers << rand(1000).to_s end
    numbers.to_a.join(' ')
end

def doTests(numberLimit)
    results = []
    100.times do
        numbers = getRandomNumber(numberLimit)
		#puts numbers
        instructions = `#{'./push_swap ' + numbers}`
        command = '/bin/echo -n \'' + instructions + '\' | ./checker ' + numbers;
        if `#{command}`[0..1] != 'OK' then puts "failure".center(10).red; return end
        results << instructions.split("\n").size
    end
    print "#{results.min}".center(10).green, "#{results.max}".center(10).red, "#{results.reduce(:+).fdiv(results.size)}".center(10).blue; puts
end

print "TEST".center(30), "LOWEST".center(10), "BIGGEST".center(10), "AVERAGE".center(10); puts
print "Simple 5 random values".center(30); doTests(5)
#print "Perso 8 random values".center(30); doTests(8)
print "Middle 100 random values".center(30); doTests(100)
print "Advanced 500 random values".center(30); doTests(500)
#print "Exterme 1000 random values".center(30); doTests(1000)
