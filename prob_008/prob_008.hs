find_max xs
    | length xs >= 13 = (\x y -> if x >= y then x else y) (product (take 13 xs)) (find_max (tail xs))
    | otherwise = 0

main = do
        inp <- getLine
        nums <- return (read inp :: [Int])
        putStrLn $ show (find_max nums)
