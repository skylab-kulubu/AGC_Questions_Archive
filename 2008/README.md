# 2008
CDO is a insurence set of MBSs, MBS is a insurence that insures whether a person is able to pay back their mortgage credit or not. In worldwide, banks give mortgage credit to **everyone**. Then, they create MBSs about their pay-back possiblities to sell invesment banks.

Invesment banks buy these MBSs and they create CDOs includes MBS and other stuff, then sell them to other invesment banks and people. This concludes unpredictable cash balance and finally, 2008/Mortgage crisis occurred. In the ending of crisis, some invesment banks that which causes this crisis are saved by governments using bailouts, and they continue their operations.

For more information about crisis: [2008 financial crisis](https://en.wikipedia.org/wiki/2008_financial_crisis)

The invesment bank LABAlgo wants to buy CDOs to make profit from MBSs. For doing it, they need to estimate their values using their value calculation formulas.

After calculating MBSs values, they need to attune them to CDOs for insuring. After insurence, they sell them to their customers. A funding manager is responsible for doing this job.

The manager knows that CDOs include a lot of MBSs and he needs to select MBSs as much as possible. The bank wants to buy a lot of MBSs.

Calculating spending of MBS if insured:
```
floor((real value)*(maturity/12)*chance)
```

Calculating spending CDO if insured:
```
sum of{(selected calculated MBS values)}+(one time spending)
```

**Note: Use `double` value for division operation.**  
**Note: MBSs cannot be insured without parent CDO.**

Example input:
```
2 10 # CDO count, their total money for this job ($M)
3 2 # MBS count of first CDO, the one time spending if selects any MBS from this CDO ($K)
300 32 0.3 # Real value of MBS (K$), maturity of MBS, chance of paying credit according to the bank
250 12 0.75
100 10 0.6
2 8
1000 20 0.8
128 12 0.3
```

Wanted output:
```
8.142 5 # Remaining money as $M with double value, total buyable MBS
```
