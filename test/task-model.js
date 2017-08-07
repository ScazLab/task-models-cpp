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
                },
                {
                    "name": "attach leg-1 to top",
                    "type": "leaf",
                    "action": {
                        "conditions": [
                            ["uses", "screws"],
                            ["uses", "screwdriver"],
                            ["consumes", "top"],
                            ["support", "hold-v"]
                        ]
                    }
                }
            ]
        },
        {
            "name": "second leg",
            "type": "sequential",
            "children": [
                {
                    "name": "assemble leg-2",
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
                },
                {
                    "name": "attach leg-2 to top",
                    "type": "leaf",
                    "action": {
                        "conditions": [
                            ["uses", "screws"],
                            ["uses", "screwdriver"],
                            ["support", "hold-v"]
                        ]
                    }
                }
            ]
        },
        {
            "name": "third leg",
            "type": "sequential",
            "children": [
                {
                    "name": "assemble leg-3",
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
                },
                {
                    "name": "attach leg-3 to top",
                    "type": "leaf",
                    "action": {
                        "conditions": [
                            ["uses", "screws"],
                            ["uses", "screwdriver"],
                            ["support", "hold-v"]
                        ]
                    }
                }
            ]
        },
        {
            "name": "fourth leg",
            "type": "sequential",
            "children": [
                {
                    "name": "assemble leg-4",
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
                },
                {
                    "name": "attach leg-4 to top",
                    "type": "leaf",
                    "action": {
                        "conditions": [
                            ["uses", "screws"],
                            ["uses", "screwdriver"],
                            ["support", "hold-v"]
                        ]
                    }
                }
            ]
        }
    ]
}