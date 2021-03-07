require 'set'
ARGV[1].to_i.times do
	numbers = Set.new
	while numbers.size < ARGV[0].to_i do numbers << rand(42000000) end
	command = './push_swap '; numbers.each { |n| command += n.to_s; command += ' ' }; command += '| wc -l | tr \'\n\' \' \'';
	system(command)
end
puts