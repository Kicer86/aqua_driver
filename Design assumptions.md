
# Device for automatic temperature and lighting control in an aquarium/terrarium.

## Design assumptions:
- Temperature measurement in the aquarium and control of the heater to achieve the desired temperature
    - Waterproof temperature sensor with a minimum resolution and accuracy of 0.5°C
    - Heater control in on/off mode
    - Setting the temperature from a mobile application
    - Notifying the mobile application about:
        - Heater burnout (no/increased power consumption by the heater)
        - Exceeding the set temperature despite the heater being off
        - Inability to reach the set temperature (due to a weak heater or too high a set temperature value)
- Automatic activation and deactivation of the aquarium lighting
    - Handling a minimum of 5 channels of 12V LED lighting
    - Independent control of each channel
    - Channel brightness control
    - Defining channel activation/deactivation (brightness) times from the mobile application
    - Notifying the mobile application about:
        - Decrease/increase in current consumption by the lighting
- Power supply from the 230V network with battery backup for essential components
    - Real-time clock power backup
    - Notifying the mobile application about:
        - Loss of mains power supply
- All settings and configurations stored in non-volatile memory that does not require power.
