-- Brute force solution, takes too long

fractions :: Integral a => [(a, a)]
fractions = [(a, b) | a <- [1..12000], b <- [1..12000], gcd a b == 1]

fractions_in_range :: Integral a => [(a, a)]
fractions_in_range = filter (\(a, b) -> let q = (fromIntegral a) / (fromIntegral b) in q > 1 / 3 && q < 1 / 2) fractions

count_fractions = length fractions_in_range
