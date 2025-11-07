from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder
import pandas as pd

data=[['Milk','Bread'],['Milk','Eggs'],['Bread','Eggs'],
      ['Milk','Bread','Butter'],['Bread','Butter'],
      ['Milk','Butter'],['Bread','Eggs','Butter']]

te=TransactionEncoder()
df=pd.DataFrame(te.fit(data).transform(data),columns=te.columns_)

print("One-Hot Encoded DataFrame:\n",df)
freq=apriori(df,min_support=0.3,use_colnames=True)
print("\nFrequent Itemsets:\n",freq)
rules=association_rules(freq,metric='confidence',min_threshold=0.7)
print("\nAssociation Rules:\n",rules[['antecedents','consequents','support','confidence','lift']])


import numpy as np
from scipy.stats import chi2_contingency

observed=np.array([[30,10],[20,40]])
print("Observed Frequency Table:\n",observed)

chi2,p,dof,expected=chi2_contingency(observed)
print("\nExpected Frequency Table:\n",expected)
print("\nChi-Square Value =",round(chi2,4))
print("Degrees of Freedom =",dof)
print("P-Value =",round(p,6))

if p<0.05:
    print("\nObservation: There is a significant relationship between Gender and Preference.")
else:
    print("\nObservation: There is no significant relationship between Gender and Preference.")