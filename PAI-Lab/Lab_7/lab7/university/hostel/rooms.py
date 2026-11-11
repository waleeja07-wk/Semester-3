def room_rent(sharing):
    """Monthly rent: fewer students in a room means more rent."""
    rents = {1: 25000, 2: 15000, 3: 10000}
    return rents.get(sharing, 8000)
