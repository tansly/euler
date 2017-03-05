digit_cnt n
    | n >= 0 && n <= 9 = 1
    | otherwise = 1 + digit_cnt (n `quot` 10)

nth_pows n = [x ^ n | x <- [1..9]] -- 10^n is already n + 1 digits

powerful_nums n = filter (\x -> digit_cnt x == n) (nth_pows n)

solve_063 = sum (takeWhile (/= 0) $ map length pows)
          where pows = [powerful_nums n | n <- [1..]]
