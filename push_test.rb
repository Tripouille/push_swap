require 'set'
results = []
ARGV[1].to_i.times do
	numbers = Set.new
	while numbers.size < ARGV[0].to_i do numbers << rand(42000000).to_s end
		numbers = numbers.to_a.join(' ')
		command = './push_swap ' + numbers + '| ./checker ' + numbers;
		checkerResult = `#{command}`
		if checkerResult[0..1] === "KO" then puts "failure"; exit; end
		command = './push_swap ' + numbers + '| wc -l';
		results << `#{command}`.to_i
end
puts "lowest = #{results.min} biggest = #{results.max} average = #{results.reduce(:+).fdiv(results.size)}"