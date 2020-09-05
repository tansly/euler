until_hundred = (
        len('onetwothreefourfivesixseveneightnine')*9 +
        len('teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen') +
        len('twentythirtyfortyfiftysixtyseventyeightyninety')*10
)
hundreds = len('hundred')*9
hundred_ands = len('hundredand')*9*99
hundred_digits = len('onetwothreefourfivesixseveneightnine')*100

print(until_hundred)

print(
        until_hundred + hundreds + hundred_ands + hundred_digits + 
        until_hundred*9 + len('onethousand')
)
