leap y
    | y `mod` 100 == 0  = y `mod` 400 == 0
    | otherwise         = y `mod` 4 == 0

days_of_months y = if leap y
                       then [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
                       else [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

days = foldr (++) [] d
     where d = [days_of_months y | y <- [1901..2000]]

solve_019 = sundays 2 days -- 1 Jan 1901 is Tuesday, Sunday is 0th, Tuesday is 2nd
          where sundays _ []    = 0
                sundays a (d:ds)
                    | a == 0    = 1 + sundays (d `mod` 7) ds
                    | otherwise = sundays ((a + d) `mod` 7) ds

main = putStrLn (show solve_019)
