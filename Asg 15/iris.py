import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('iris.csv')

print("Description:")
df.describe()

# 	Sepal Length	Sepal Width	Petal Length	Petal Width
# count	150.000000	150.000000	150.000000	150.000000
# mean	5.843333	3.054000	3.758667	1.198667
# std	0.828066	0.433594	1.764420	0.763161
# min	4.300000	2.000000	1.000000	0.100000
# 25%	5.100000	2.800000	1.600000	0.300000
# 50%	5.800000	3.000000	4.350000	1.300000
# 75%	6.400000	3.300000	5.100000	1.800000
# max	7.900000	4.400000	6.900000	2.500000

print("Minimum value:")
df.min()

# Minimum value:
# Sepal Length            4.3
# Sepal Width               2
# Petal Length              1
# Petal Width             0.1
# Species         Iris-setosa
# dtype: object

print("Maximum value:")
df.max()

# Maximum value:
# Sepal Length               7.9
# Sepal Width                4.4
# Petal Length               6.9
# Petal Width                2.5
# Species         Iris-virginica
# dtype: object

print("Average value:")
df.mean()

# Average value:
# Sepal Length    5.843333
# Sepal Width     3.054000
# Petal Length    3.758667
# Petal Width     1.198667
# dtype: float64

print("Std dev value:")
df.std()

# Std dev value:
# Sepal Length    0.828066
# Sepal Width     0.433594
# Petal Length    1.764420
# Petal Width     0.763161
# dtype: float64

print("Variance value:")
df.var()

# Variance value:
# Sepal Length    0.685694
# Sepal Width     0.188004
# Petal Length    3.113179
# Petal Width     0.582414
# dtype: float64

print("Percentiles:")
df.quantile([0, .25, .5, .75, 1]) 

# Percentiles:
# Sepal Length	Sepal Width	Petal Length	Petal Width
# 0.00	4.3	2.0	1.00	0.1
# 0.25	5.1	2.8	1.60	0.3
# 0.50	5.8	3.0	4.35	1.3
# 0.75	6.4	3.3	5.10	1.8
# 1.00	7.9	4.4	6.90	2.5

print("Histograms:")
df.hist()

print("BoxPlots:")
df.boxplot()