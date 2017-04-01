digitsum n
    | n < 10 = n
    | otherwise = n `mod` 10 + digitsum (n `quot` 10)

solve = maximum [digitsum (x^y) | x <- [99,98..80], y <- [99,98..80]]
