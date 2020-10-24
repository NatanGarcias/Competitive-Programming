Select products.name, providers.name
from products inner join providers on providers.id = products.id_providers 
where products.id_categories = 6;