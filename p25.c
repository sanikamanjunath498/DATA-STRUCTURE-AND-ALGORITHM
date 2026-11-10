import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    # Perform a left join on 'personId' to keep all rows from the person table
    merged_df = pd.merge(person, address, on='personId', how='left')
    
    # Select the required columns: firstName, lastName, city, state
    return merged_df[['firstName', 'lastName', 'city', 'state']]
