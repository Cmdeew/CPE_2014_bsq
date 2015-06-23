#!/usr/local/bin/perl -w
## map_gen.pl for bsq in /home/rieux-_t/Documents/rendu/Elem/CPE_2014_bsq
## 
## Made by thomas rieux-laucat
## Login   <rieux-_t@epitech.net>
## 
## Started on  Mon Jan 12 14:18:37 2015 thomas rieux-laucat
## Last update Thu Jan 15 18:30:10 2015 thomas rieux-laucat
##

if ((scalar @ARGV) != 3)
{
    printf "program xy density\n";
    exit;
}

my $x = $ARGV[0];
my $y = $ARGV[1];
my $density = $ARGV[2];
my $i = 0;
my $j = 0;

print $y . "\n";

while ($i < $y)
{
    $j = 0;
    while ($j < $x)
    {
	if (int(rand($y)*2) < $density)
	{
	    print "o";
	}
	else
	{
	    print ".";
	}
	$j++;
    }
    print "\n";
    $i++;
}
