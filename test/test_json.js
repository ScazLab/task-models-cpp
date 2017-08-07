{
    "name": "task",
    "type": "sequential",
    "children": [
        {
            "name": "first leg",
            "type": "sequential",
            "children": [
                {
                    "name": "assemble leg-1",
                    "type": "leaf",
                    "action": {
                        "conditions": [
                            ["uses", "joints"],
                            ["uses", "screws"],
                            ["uses", "screwdriver"],
                            ["consumes", "leg"],
                            ["support", "hold-h"]
                        ]
                    }
                }
            ]
        }
    ]
}