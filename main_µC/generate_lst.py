
Import("env")

# Define a custom function to generate the .lst file using objdump
def generate_lst_file(target, source, env):
    elf_path = f"$BUILD_DIR/{env.get('PROGNAME')}.elf"
    lst_path = f"$BUILD_DIR/{env.get('PROGNAME')}.lst"

    objdump_cmd = f"avr-objdump -d -S {elf_path} > {lst_path}"
    print(f"Running command: {objdump_cmd}")
    env.Execute(objdump_cmd)

# Add the custom function as a post-build step
env.AddPostAction("$BUILD_DIR/${PROGNAME}.hex", generate_lst_file)
