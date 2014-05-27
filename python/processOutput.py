#!/usr/bin/python
import sys

if __name__ == "__main__":
	if( len(sys.argv)<3):
		print("Not enough args")
		sys.exit(0)
	
	inp = sys.argv[1]
	out = sys.argv[2]
	# We need to read in all the current paragraphs
	file_in = open(inp, 'r')
	file_out = open(out, 'r')
	
	in_content = file_in.read()
	out_content = file_out.read()

	in_ary=in_content.rstrip().split('\n\n')
	out_ary=out_content.rstrip().split('\n\n')

	for tweet in in_ary:
		if tweet not in out_ary:
			out_ary.append(tweet)
	
	file_in.close()
	file_out.close()

	file_out = open(out,'w')
	
	for tweet in out_ary:
		file_out.write(tweet)
		file_out.write('\n\n')

	
 
