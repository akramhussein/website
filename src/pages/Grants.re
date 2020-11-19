module Styles = {
  open Css;

  let sectionContainer = bg =>
    style([
      position(`relative),
      background(`url(bg)),
      unsafe("backgroundSize", "100% auto"),
      backgroundRepeat(`noRepeat),
      padding(`rem(2.)),
      media(Theme.MediaQuery.desktop, [padding(`zero)]),
    ]);

  let grantsBackground =
    style([
      backgroundColor(Theme.Colors.digitalBlack),
      width(`percent(100.)),
      height(`percent(100.)),
      paddingTop(`rem(8.)),
      paddingBottom(`rem(6.)),
    ]);

  let section =
    style([
      width(`percent(100.)),
      maxWidth(`rem(71.)),
      margin2(~v=`auto, ~h=`auto),
      paddingTop(`rem(3.)),
      backgroundPosition(`rem(-6.5), `rem(-2.)),
      gridTemplateColumns([`em(14.), `auto]),
      selector("> aside", [gridColumnStart(1)]),
      selector("> :not(aside)", [gridColumnStart(2)]),
      selector("> img", [width(`percent(100.))]),
      media(Theme.MediaQuery.desktop, [paddingLeft(`rem(16.))]),
    ]);

  let typesOfGrantsImage =
    style([
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/MinaSpectrumBackground.jpg")),
      width(`percent(100.)),
      height(`percent(100.)),
      padding2(~v=`rem(4.), ~h=`zero),
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
      overflow(`hidden),
      media(
        Theme.MediaQuery.notMobile,
        [padding2(~v=`zero, ~h=`zero), height(`rem(43.))],
      ),
    ]);

  let typeOfGrantsContainer =
    style([
      width(`percent(100.)),
      padding(`rem(2.)),
      backgroundColor(white),
    ]);

  let faqList =
    style([
      marginLeft(`rem(2.)),
      selector("li", [marginTop(`rem(1.))]),
    ]);

  let background =
    style([
      backgroundImage(
        `url("/static/img/community-page/SectionCulture_Values.jpg"),
      ),
      backgroundSize(`cover),
      paddingTop(`rem(4.)),
      media(Theme.MediaQuery.notMobile, [paddingTop(`rem(12.))]),
    ]);

  let grantDescriptionOuterContainer =
    style([
      display(`flex),
      flexDirection(`column),
      width(`percent(100.)),
    ]);

  let grantDescriptionInnerContainer =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceBetween),
      media(Theme.MediaQuery.tablet, [flexDirection(`row)]),
    ]);

  let grantTwoColumnContent =
    style([
      marginTop(`rem(1.5)),
      width(`percent(100.)),
      media(
        Theme.MediaQuery.tablet,
        [width(`percent(48.)), marginTop(`zero)],
      ),
    ]);

  let grantThreeColumnContent =
    style([
      marginTop(`rem(2.)),
      width(`percent(100.)),
      media(
        Theme.MediaQuery.tablet,
        [width(`percent(30.)), marginTop(`zero)],
      ),
    ]);

  let link =
    merge([
      Theme.Type.link,
      style([
        fontSize(`rem(1.)),
        lineHeight(`rem(1.5)),
        media(
          Theme.MediaQuery.tablet,
          [fontSize(`rem(1.125)), lineHeight(`rem(1.69))],
        ),
      ]),
    ]);
};

module Section = {
  [@react.component]
  let make = (~title, ~subhead, ~slug, ~children) => {
    <section className=Styles.section id=slug>
      <h2 className=Theme.Type.h2> {React.string(title)} </h2>
      <Spacer height=1.5 />
      <p className=Theme.Type.sectionSubhead> {React.string(subhead)} </p>
      <Spacer height=4. />
      children
      <Spacer height=6.5 />
    </section>;
  };
};

module FAQ = {
  module FAQRow = {
    [@react.component]
    let make = (~title, ~children) => {
      <div>
        <Spacer height=3.5 />
        <h4 className=Theme.Type.h4> {React.string(title)} </h4>
        <Spacer height=1. />
        children
      </div>;
    };
  };
  [@react.component]
  let make = () => {
    <Wrapped>
      <Section title="General Questions" subhead="" slug="faq">
        <hr className=Theme.Type.divider />
        <div>
          <FAQRow
            title="Where do I begin if I want to understand how Mina works?">
            <Spacer height=1. />
            <span className=Theme.Type.paragraph>
              <span> {React.string("Visit ")} </span>
              <Next.Link href="/docs">
                <span className=Styles.link>
                  {React.string("the Mina Docs.")}
                </span>
              </Next.Link>
            </span>
          </FAQRow>
          <FAQRow title="Can teams apply?">
            <Spacer height=1. />
            <span className=Theme.Type.paragraph>
              <span>
                {React.string(
                   "Yes, both individuals and teams are eligible to apply.",
                 )}
              </span>
            </span>
          </FAQRow>
          <FAQRow
            title="How do I increase my chance of getting selected for a grant?">
            <Spacer height=1. />
            <span className=Theme.Type.paragraph>
              <span> {React.string("See the ")} </span>
              <a href=Constants.projectGrantApplication>
                <span className=Styles.link>
                  {React.string("Application Process ")}
                </span>
              </a>
              <span>
                {React.string(
                   "section for selection criteria. Please also reach out to us if you have any unique skills that don't apply to current projects. You can also start ",
                 )}
              </span>
              <a href=Constants.minaGithub>
                <span className=Styles.link>
                  {React.string("contributing code to Mina ")}
                </span>
              </a>
              <span>
                {React.string(
                   "-- grants will give precedence to previous contributors.",
                 )}
              </span>
            </span>
          </FAQRow>
          <FAQRow title="What is expected of me, if I receive a grant?">
            <Spacer height=1. />
            <span className=Theme.Type.paragraph>
              <span> {React.string("We expect grant recipients to:")} </span>
              <ul className=Styles.faqList>
                <li>
                  {React.string(
                     "Communicate effectively and create a tight feedback loop",
                   )}
                </li>
                <li> {React.string("Meet project milestones")} </li>
                <li>
                  {React.string(
                     "Serve as ambassadors of Mina in the larger crypto community",
                   )}
                </li>
              </ul>
            </span>
          </FAQRow>
          <FAQRow title="Where do I go if I need help?">
            <Spacer height=1. />
            <span className=Theme.Type.paragraph>
              <span>
                {React.string(
                   "Join the Mina Discord channel or reach out to grants[at]o1labs[dot]org to get help.",
                 )}
              </span>
            </span>
          </FAQRow>
        </div>
      </Section>
    </Wrapped>;
  };
};

module Project = {
  type section = {
    title: string,
    copy: string,
  };

  type twoColumnRow = {
    firstColumn: section,
    secondColumn: section,
  };

  type threeColumnRow = {
    firstColumn: section,
    secondColumn: section,
    thirdColumn: section,
  };

  module TwoColumn = {
    [@react.component]
    let make = (~title, ~rows: array(twoColumnRow), ~buttonUrl) =>
      <div className=Styles.grantDescriptionOuterContainer>
        <hr className=Theme.Type.divider />
        <Spacer height=1. />
        <h3 className=Theme.Type.h3> {React.string(title)} </h3>
        <Spacer height=2. />
        {rows
         |> Array.map((row: twoColumnRow) => {
              <div key={row.firstColumn.title}>
                <div className=Styles.grantDescriptionInnerContainer>
                  <div className=Styles.grantTwoColumnContent>
                    <h4 className=Theme.Type.h4>
                      {React.string(row.firstColumn.title)}
                    </h4>
                    <Spacer height=1. />
                    <p className=Theme.Type.paragraph>
                      {React.string(row.firstColumn.copy)}
                    </p>
                  </div>
                  <div className=Styles.grantTwoColumnContent>
                    <h4 className=Theme.Type.h4>
                      {React.string(row.secondColumn.title)}
                    </h4>
                    <Spacer height=1. />
                    <p className=Theme.Type.paragraph>
                      {React.string(row.secondColumn.copy)}
                    </p>
                  </div>
                </div>
                <Spacer height=4. />
              </div>
            })
         |> React.array}
        <Spacer height=4. />
        <span className=Css.(style([marginLeft(`auto)]))>
          <Button
            href={`External(buttonUrl)}
            bgColor=Theme.Colors.orange
            width={`rem(7.)}>
            {React.string("Apply")}
            <Icon kind=Icon.ArrowRightSmall />
          </Button>
        </span>
      </div>;
  };

  module ThreeColumn = {
    [@react.component]
    let make = (~title, ~rows: array(threeColumnRow), ~buttonUrl) =>
      <div className=Styles.grantDescriptionOuterContainer>
        <hr className=Theme.Type.divider />
        <Spacer height=1. />
        <h3 className=Theme.Type.h3> {React.string(title)} </h3>
        <Spacer height=2. />
        {rows
         |> Array.map((row: threeColumnRow) =>
              <div key={row.firstColumn.title}>
                <div className=Styles.grantDescriptionInnerContainer>
                  <div className=Styles.grantThreeColumnContent>
                    <h4 className=Theme.Type.h4>
                      {React.string(row.firstColumn.title)}
                    </h4>
                    <Spacer height=1. />
                    <p className=Theme.Type.paragraph>
                      {React.string(row.firstColumn.copy)}
                    </p>
                  </div>
                  <div className=Styles.grantThreeColumnContent>
                    <h4 className=Theme.Type.h4>
                      {React.string(row.secondColumn.copy)}
                    </h4>
                    <Spacer height=1. />
                    <p className=Theme.Type.paragraph>
                      {React.string(row.secondColumn.copy)}
                    </p>
                  </div>
                  <div className=Styles.grantThreeColumnContent>
                    <h4 className=Theme.Type.h4>
                      {React.string(row.thirdColumn.title)}
                    </h4>
                    <Spacer height=1. />
                    <p className=Theme.Type.paragraph>
                      {React.string(row.thirdColumn.copy)}
                    </p>
                  </div>
                </div>
                <Spacer height=4. />
              </div>
            )
         |> React.array}
        <span className=Css.(style([marginLeft(`auto)]))>
          <Button
            href={`External(buttonUrl)}
            bgColor=Theme.Colors.orange
            width={`rem(7.)}>
            {React.string("Apply")}
            <Icon kind=Icon.ArrowRightSmall />
          </Button>
        </span>
      </div>;
  };
};

module FrontEndProjects = {
  [@react.component]
  let make = () =>
    <div
      className={Styles.sectionContainer("/static/img/tech-gradient-1.jpg")}>
      <Spacer height=6.5 />
      <hr className=Theme.Type.divider />
      <Section
        title="Product / Front-End Projects"
        subhead={js|Assist with building interfaces and platforms for users to interact with Mina.|js}
        slug="frontend">
        // <Button href={`Internal("/docs")} bgColor=Theme.Colors.orange>
        //   {React.string("Install SDK")}
        //   <Icon kind=Icon.ArrowRightMedium />
        // </Button>

          <Spacer height=4. />
          <Project.TwoColumn
            title="Graph QL API"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $10,000 USD per month of Mina tokens (minimum 2 months commitment)|js},
                },
                secondColumn: {
                  title: "Description",
                  copy: {js|Help Mina update its GraphQL API to support new use cases. Work closely with O(1) Labs Engineering to gather requirements. You must be familiar with OCaml.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
          <Project.ThreeColumn
            title="Telemetry Health Dashboard"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $10,000 USD per month of Mina tokens|js},
                },
                secondColumn: {
                  title: "Project Type",
                  copy: {js|Open source|js},
                },
                thirdColumn: {
                  title: "Overview",
                  copy: {js|Build a high-level dashboard that describes the current state of the network by aggregating data from as many nodes as it has access to.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
          <Project.ThreeColumn
            title="Browser Wallet (with optional chrome extension)"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $10,000 USD per month of Mina tokens|js},
                },
                secondColumn: {
                  title: "Project Type",
                  copy: {js|Open source|js},
                },
                thirdColumn: {
                  title: "Overview",
                  copy: {js|Enable sending, receiving, and delegating Mina tokens using a web wallet with support for the Ledger.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
          <Project.TwoColumn
            title="Mobile Wallet"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $10,000 USD per month of Mina tokens (minimum 2 months commitment)|js},
                },
                secondColumn: {
                  title: "Overview",
                  copy: {js|Enable sending, receiving, and delegating Mina tokens using a Mobile Wallet.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
        </Section>
    </div>;
};

module ProtocolProjects = {
  [@react.component]
  let make = () =>
    <div
      className={Styles.sectionContainer("/static/img/tech-gradient-1.jpg")}>
      <Spacer height=6.5 />
      <hr className=Theme.Type.divider />
      <Section
        title="Protocol Projects"
        subhead={js|Contribute to engineering projects to develop the core technology underlying the protocol.|js}
        slug="protocol">
        // <Button href={`Internal("/docs")} bgColor=Theme.Colors.orange>
        //   {React.string("Install SDK")}
        //   <Icon kind=Icon.ArrowRightMedium />
        // </Button>

          <Spacer height=4. />
          <Project.TwoColumn
            title="Stablecoin Support"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Integration fee as grant or initial deposit amount|js},
                },
                secondColumn: {
                  title: "Description",
                  copy: {js|Offer a US dollar backed programmable stablecoin on the Mina Protocol.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
          <Project.ThreeColumn
            title="Alternative Client Implementation (e.g. Rust)"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $100,000 USD of Mina tokens|js},
                },
                secondColumn: {
                  title: "Project Type",
                  copy: {js|Open source|js},
                },
                thirdColumn: {
                  title: "Overview",
                  copy: {js|Enable Mina nodes to parse and verify the Mina transactions, its smart contracts and everything related. Provide an interfaces to create transactions, product blocks, and create snarks in Mina.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
        </Section>
    </div>;
};

module MarketingAndCommunityProjects = {
  [@react.component]
  let make = () =>
    <div
      className={Styles.sectionContainer("/static/img/tech-gradient-1.jpg")}>
      <Spacer height=6.5 />
      <hr className=Theme.Type.divider />
      <Section
        title="Marketing and Community Projects"
        subhead={js|Help to build and grow Mina's community by serving as ambassadors, creating content, and other initiatives.|js}
        slug="marketing-community">
        // <Button href={`Internal("/docs")} bgColor=Theme.Colors.orange>
        //   {React.string("Install SDK")}
        //   <Icon kind=Icon.ArrowRightMedium />
        // </Button>

          <Spacer height=4. />
          <Project.TwoColumn
            title="Technical Community Ambassadors"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $1000 USD of Mina tokens per month|js},
                },
                secondColumn: {
                  title: "Description",
                  copy: {js|Grow, excite and organize Mina’s technical community globally by organizing virtual meetups, supporting the community in testnet activities, establishing a presence on geographically-relevant platforms (ex. WeChat in China), producing and sharing educational content, recruiting new community members and being a spokesperson for the project. As our community grows and evolves, so will this role. The ideal candidate will be equal parts passionate, flexible, and dedicated.|js},
                },
              },
              {
                firstColumn: {
                  title: "Minimum qualifications",
                  copy: {js|Native fluency in the dominant language of your region (Ex. German for Germany), plus an ability to communicate effectively in written and spoken English.|js},
                },
                secondColumn: {
                  title: "Relevant Countries/Regions",
                  copy: {js|China / France / Germany / India / Indonesia / Japan / Korea / Latin America (Portuguese-speaking) / Latin America (Spanish-speaking) / Netherlands / Nigeria / Russia / Turkey / UK / US|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=3. />
          <Project.TwoColumn
            title="Intro video for Mina"
            rows=[|
              {
                firstColumn: {
                  title: "Allocation",
                  copy: {js|Minimum of $1000 USD of Mina tokens|js},
                },
                secondColumn: {
                  title: "Description",
                  copy: {js|Create a short video that introduces Mina, highlights key differentiators, discusses Mina’s novel use of zk-SNARKs, use cases, etc.|js},
                },
              },
            |]
            buttonUrl=Constants.projectGrantApplication
          />
          <Spacer height=5. />
          <p className=Theme.Type.paragraph>
            <em>
              {React.string(
                 "We are also open to any of your suggestions for a grant! Submit an application and we will review it.",
               )}
            </em>
          </p>
        </Section>
    </div>;
};

module HowToApply = {
  [@react.component]
  let make = () =>
    <section id="how-to-apply">
      <div className=Styles.background>
        <FeaturedSingleRow
          row={
            FeaturedSingleRow.Row.rowType: ImageRightCopyLeft,
            title: "How to Apply",
            copySize: `Small,
            description: {js|Fill out this form to apply for an open project. Applicants who are selected will have the opportunity to claim or “lock” the project so that they can work on it exclusively.|js},
            textColor: Theme.Colors.black,
            image: "/static/img/community-page/09_Community_4_1504x1040.jpg",
            background: Image(""),
            contentBackground: Color(Theme.Colors.white),
            link:
              FeaturedSingleRow.Row.Button({
                FeaturedSingleRow.Row.buttonText: "Apply Now",
                buttonColor: Theme.Colors.orange,
                buttonTextColor: Theme.Colors.white,
                dark: false,
                href: `External(Constants.projectGrantApplication),
              }),
          }>
          <Spacer height=4. />
          <hr className=Theme.Type.divider />
          <Spacer height=4. />
          <CultureGrid
            title="Evaluation Criteria"
            description={
              Some(
                <p className=Theme.Type.paragraph>
                  <span>
                    {React.string(
                       "All grants are subject to approval by O(1) Labs. ",
                     )}
                  </span>
                  <span>
                    {React.string(
                       "By submitting an application, you agree to our ",
                     )}
                  </span>
                  <Next.Link href="/privacy">
                    <span className=Styles.link>
                      {React.string("Privacy Policy")}
                    </span>
                  </Next.Link>
                </p>,
              )
            }
            sections=[|
              {
                title: "01",
                copy: "Previous experience in the domain of the project",
              },
              {
                title: "02",
                copy: "Previous open-source contributions is a plus, but not necessary",
              },
              {
                title: "03",
                copy: "Prior involvement in the Mina community is a plus, but not necessary",
              },
              {
                title: "04",
                copy: "Interest in Mina and cryptocurrencies is a plus, but not necessary",
              },
            |]
          />
          <Spacer height=7. />
        </FeaturedSingleRow>
      </div>
    </section>;
};

[@react.component]
let make = (~grants) => {
  <Page title="Mina Cryptocurrency Protocol" footerColor=Theme.Colors.orange>
    <div className=Nav.Styles.spacer />
    <Hero
      title=""
      header={Some("Grants Program")}
      copy={
        Some(
          "The Project Grant program is designed to encourage community members to work on projects related to developing the Mina protocol and community.",
        )
      }
      background={
        Theme.desktop: "/static/img/backgrounds/GrantsHeroDesktop.jpg",
        Theme.tablet: "/static/img/backgrounds/GrantsHeroTablet.jpg",
        Theme.mobile: "/static/img/backgrounds/GrantsHeroMobile.jpg",
      }
    />
    <div className=Styles.typesOfGrantsImage>
      <Wrapped>
        <div className=Styles.typeOfGrantsContainer>
          <Spacer height=2. />
          <Rule />
          <TypesOfGrants />
          <Rule />
          <Spacer height=2. />
        </div>
      </Wrapped>
    </div>
    <GrantsNav.SideNav />
    <GrantsNav.Dropdown />
    <FrontEndProjects />
    <ProtocolProjects />
    <MarketingAndCommunityProjects />
    <HowToApply />
    <section id="contributors">
      <div className=Styles.grantsBackground>
        <Wrapped>
          <Rule color=Theme.Colors.white />
          <Carousel
            title="Completed and Current Grant Projects"
            copy=None
            cardKind={Carousel.Grants(grants)}
            dark=false
            numberOfItems={Array.length(grants)}
          />
        </Wrapped>
      </div>
    </section>
    <FAQ />
  </Page>;
};

Next.injectGetInitialProps(make, _ => {
  Contentful.getEntries(
    Lazy.force(Contentful.client),
    {
      "include": 1,
      "content_type": ContentType.Grant.id,
      //"order": "-fields.title",
    },
  )
  |> Promise.map((entries: ContentType.Grant.entries) => {
       let grants =
         Array.map((e: ContentType.Grant.entry) => e.fields, entries.items);
       {"grants": grants};
     })
});
